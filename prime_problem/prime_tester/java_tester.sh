if [ -e "do" ]; then
    rm do
fi
g++ -o checker checker.cpp
javac main.java
if [ -e "main.class" ]; then
    python3 tester.py <input
    ./checker
else
    echo "compilation error: do not found"
fi

