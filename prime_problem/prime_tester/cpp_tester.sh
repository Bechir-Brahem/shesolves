if [ -e "do" ]; then
    rm do
fi
g++ -o checker checker.cpp
g++ -o do main.cpp
if [ -e "do" ]; then
    python3 tester.py <input
    ./checker
else
    echo "compilation error: do not found"
fi
