//C++11的
//http://www.mitbbs.com/article_t/JobHunting/32845585.html
//https://github.com/skyyyyy/algorithm/blob/master/H2O.cpp

condition_variable gOReady, gHReady;
int atomcountH = 2, atomcountO = 1;

void O() {
    unique_lock<mutex> l(gLock);
    gHReady.wait(l, []{return atomcountO > 0;});
   
    cout << "O" << endl;
    if(--atomcountO == 0 && atomcountH == 0) {
        atomcountH = 2;
        atomcountO = 1;
        cout << "water" << endl;
    }
    gOReady.notify_all();
}

void H() {
    unique_lock<mutex> l(gLock);
    gOReady.wait(l, []{return atomcountH > 0;});
   
    cout << "H" << endl;
    if(--atomcountH == 0 && atomcountO == 0) {
        atomcountH = 2;
        atomcountO = 1;
        cout << "water" << endl;
    }
    gHReady.notify_all();
}
