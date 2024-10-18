int reverse(int x) {
    int newInt = 0;
    while (x) {
        newInt = (newInt * 10) + (x % 10);
        x = x / 10;
    }
    return newInt;
}