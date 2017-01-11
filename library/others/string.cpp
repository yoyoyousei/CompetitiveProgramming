//baseに含まれるfromをtoへ置換
void replaceStr(string &base, string from, string to) {
    auto pos = base.find(from);
    while (pos != string::npos) {
        base.replace(pos, from.size(), to);
        pos = base.find(from, pos + to.size());
    }
}