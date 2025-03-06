#!/bin/bash

MINISHELL="./minishell" # Path to the minishell executable
ITERATIONS=1000000 # Number of iterations to run
TEMP_DIR="/tmp/minishell_fuzzing"
TEMP_MINISHELL="$TEMP_DIR/minishell"
LOGFILE="fuzzing_errors.log" # Output file for crash details
SUCCESS_COUNT=0
FAILURE_COUNT=0

CHARACTER_LENGTH="10"  # Example: fixed value "100" or range "50,200"
ERROR_CODES=("134" "139" "141" "142" "143" "144" "152" "153" "154" "255")

function generate_random_length() {
    if [[ $CHARACTER_LENGTH == *","* ]]; then
        IFS=',' read -r -a LENGTH_RANGE <<< "$CHARACTER_LENGTH"
        echo $((RANDOM % (LENGTH_RANGE[1] - LENGTH_RANGE[0] + 1) + LENGTH_RANGE[0]))
    else
        echo $CHARACTER_LENGTH
    fi
}

# "<>|'\"a-zA-A0-9!@#$%^&*_+-=,.:{()[]}"

generate_random_input() {
    LENGTH=$(generate_random_length)
    cat /dev/urandom | tr -dc "<>|'\"a-zA-A0-9!@#$%^&*_+-=,.:{()[]}" | head -c "$LENGTH" # Generate random input with the characters between ''
}

mkdir -p "$TEMP_DIR"
cp "$MINISHELL" "$TEMP_MINISHELL"
> "$LOGFILE"

echo -e "\033[1;33mStarting fuzzing... ($ITERATIONS iterations)\033[0m"
for ((i = 1; i <= ITERATIONS; i++)); do
    FUZZ_INPUT=$(generate_random_input)

    pushd "$TEMP_DIR" > /dev/null

    echo -e "\033[1;31mString : $FUZZ_INPUT\033[0m"
    OUTPUT=$(echo "$FUZZ_INPUT" | ./minishell 2>&1)
    EXIT_CODE=$?

    popd > /dev/null

    if printf "%s\n" "${ERROR_CODES[@]}" | grep -qx "$EXIT_CODE"; then
        FAILURE_COUNT=$((FAILURE_COUNT + 1))
        echo -e "\033[1;31mCrash detected on test $i!\033[0m"
        echo "Input causing crash:" >> "$LOGFILE"
        echo "$FUZZ_INPUT" >> "$LOGFILE"
        echo "Error output:" >> "$LOGFILE"
        echo "$OUTPUT" >> "$LOGFILE"
        echo "-----------------------------------" >> "$LOGFILE"
    else
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    fi

    clear
    echo -e "\033[1;34mProgress: $i/$ITERATIONS\033[0m"
    echo -e "\033[1;32mSuccessful tests: $SUCCESS_COUNT\033[0m"
    echo -e "\033[1;31mFailed tests: $FAILURE_COUNT\033[0m"
done

clear
echo -e "\033[1;33mFuzzing completed.\033[0m"
echo -e "\033[1;32mSuccessful tests: $SUCCESS_COUNT\033[0m"
echo -e "\033[1;31mFailed tests: $FAILURE_COUNT\033[0m"
echo -e "Success rate: \033[1;32m$((SUCCESS_COUNT * 100 / ITERATIONS))%\033[0m"
echo -e "Crash details saved in: \033[1;34m$LOGFILE\033[0m"
