assign 은 지정하다 라는 뜻을 가진다
만약
mystring 에 str에
str.assign("abc");
란 값을 넣게 된다면?
str에 원래 있던 문자열이 지워지고 abc가 들어간다.
MyString& assign(const MyString& str);
MyString& assign(const char\* str);

그렇다면
...
