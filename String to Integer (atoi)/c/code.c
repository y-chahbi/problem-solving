int myAtoi(char* s) {
    int sign = 1;
    double total = 0;
    int tmp = 0;


    int i = 0;
    while (s[i] == ' ') i++;


    if (s[i] == '-' || s[i] == '+') {

        if (s[i] == '-')
            sign = -1;
        i++;
    }

    while (s[i] && (s[i] >= '0' && s[i] <= '9')) {
        tmp = s[i] - '0';
        total = (total * 10) + tmp;
        i++;
    }

    if ((total * sign) > 2147483647)
        return (2147483647);
    return (total * sign) ;
}