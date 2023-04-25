//
// Created by jiatianlong on 2022/4/27.
//
#include "Pig.h"

int main(){
    Pig pig;
    Pig* pig_p = new Pig((char*)"–ª—∑",50);

    Pig pig1 = pig;
    pig1.setName((char *)"’≈Œﬁº…");
    pig1.setAge(20);
    pig1.getName();
    Pig::Update(pig_p);

    pig1.showPigInfo();

    pig.setPig(pig1);
    pig.showPigInfo();

    friendPig(pig1,(char *)"÷‹‹∆»Ù",18);
    pig1.getName();
    pig1.showPigInfo();
    delete(pig_p);
}