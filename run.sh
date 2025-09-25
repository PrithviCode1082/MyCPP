# If you're using clang

#!/bin/bash

if [ ! -f main ] || [ main.cpp -nt main ]; then
    echo "🛠️ Compiling with clang++..."
    start_time=$(date +%s.%N)

    if clang++ main.cpp -o main -std=c++17 -O2; then
        end_time=$(date +%s.%N)
        compile_time=$(echo "$end_time - $start_time" | bc)
        echo "✅ Compilation successful in ${compile_time}s"
        echo "🚀 Running program..."
        ./main
    else
        echo "❌ Compilation failed"
    fi
else
    echo "⚡ No need to recompile. Running existing binary..."
    ./main
fi



# If you're using g++
if [ ! -f main ] || [ main.cpp -nt main ]; then
        echo "Compiling..."
        start_time=$(date +%s.%N)
        if g++ main.cpp -o main; then
            end_time=$(date +%s.%N)
            compile_time=$(echo "$end_time - $start_time" | bc)
            echo "✅ Compilation successful in ${compile_time}s"
            ./main
        else
            echo "❌ Compilation failed"
        fi
    else
        ./main
    fi
