#pragma once

string hashF(string strToHash){

    const hash<string> hasher;
    const auto hash = hasher(strToHash);
    string strHashed = to_string(hash);

    return strHashed;
}
