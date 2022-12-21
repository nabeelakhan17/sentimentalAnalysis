#include "DSString.h"

DSString::DSString() {
    data = nullptr;

}

DSString::DSString(const char *d) {
    data = new char[strlen(d) + 1];
    strcpy(data, d);
    data[strlen(d)] = '\0';

}

DSString::DSString(const DSString &d) {
    data = new char[strlen(d.data) + 1];
    strcpy(data, d.data);
    data[strlen(d.data)] = '\0';
}

DSString::~DSString() {
    delete[] data;

}

DSString &DSString::operator=(const DSString &d) {
    if(data != nullptr) {
        delete[] data;
    }
    data = new char[strlen(d.data) + 1];
    strcpy(data, d.data);
    data[strlen(d.data)] = '\0';
    return *this;
}

DSString DSString::operator+(const DSString &rhs) const {
    char* temp = new char[strlen(data)+strlen(rhs.data)+1];
    strcat(temp, data);
    strcat(temp, rhs.data);
    temp[strlen(data)+strlen(rhs.data)] = '\0';
    DSString str = temp;
    return str;
}

bool DSString::operator==(const DSString &rhs) const {
    return strcmp(data, rhs.data) == 0;
}

bool DSString::operator<(const DSString &rhs) const {
    return strcmp(data, rhs.data) < 0;
}

DSString DSString::substring(size_t start, size_t numChars) const {
    char *str = new char[numChars + 1];
    strncpy(str, data + start, numChars);
    str[numChars] = '\0';
    DSString temp = str;
    return temp;
}

const char *DSString::c_str() const {
    return data;
}

std::ostream &operator<<(std::ostream &out, const DSString &str) {
    out << str.data;
    return out;
}

DSVector<DSString> DSString::tokenize() {
    DSVector<DSString> individual;
    char delimeters[] = " ,.!?";
    char* token = strtok(data, delimeters);
    while (token != nullptr) {
        individual.push_back(token);
        token = strtok(nullptr, delimeters);
    }
    return individual;
}

void DSString::toLower() {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = tolower(data[i]);
    }
}





