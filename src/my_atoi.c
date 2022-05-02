//
// Created by Ululate Leoma on 5/2/22.
//
int my_atoi (const char *c) {
    char *ch = (char *) c;
    int res = 0, sign = 1;
    while (*ch == ' ') {
        ch++; }

    if (*ch == '-' || *ch == '+') {
        sign = 1 - 2 * (*ch++ == '-');}

    while (*ch >= '0' && *ch <= '9') {
        res = res * 10 + *ch++ - '0'; }
    return res*sign;
}
