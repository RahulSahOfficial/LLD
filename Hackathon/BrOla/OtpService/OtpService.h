#ifndef OTP_SERVICE_H
#define OTP_SERVICE_H
#include <bits/stdc++.h>
using namespace std;
class OtpService{
    OtpService(){}
    public:
    static string generateOtp(int length){
        string otp;
        for(int i=0;i<length;i++){
            otp+='0'+rand()%10;
        }
        return otp;
    }
};
#endif