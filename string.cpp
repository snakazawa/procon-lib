// 1•¶šsplit —vsstream
vector<string> split(const string &str, char delim) {
	istringstream iss(str); string tmp; vector<string> res;
	while(getline(iss, tmp, delim)) res.push_back(tmp);
	return res;
}

// •¡”•¶šsplit
vector<string> split(const string &str, const string &delim = " ") {
    int start = 0, pos;
    vector<string> result;
    
    while ( (pos = str.find_first_of( delim, start) ) != string::npos ) {
        if (pos - start != 0)
            result.push_back( str.substr( start, pos - start) );
        start = pos + 1;
    }
    if (str.size() - start != 0)
        result.push_back( str.substr( start, str.size() - start ) );

    return result;
}

// o—Í‚·‚é¬”‚ÌŒ…”
// cout << fixied << setprecision(9) << x << endl;
