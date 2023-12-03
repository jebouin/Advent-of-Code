int readInt() {
    char c;
    bool start = false, neg = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if((c < '0' || c > '9') && c != '-') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		if(c == '-') neg = true;
		else ans += c - '0';
	}
    return neg ? -ans : ans;
}
