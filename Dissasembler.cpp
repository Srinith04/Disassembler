#include <iostream>

#include <cstdbool>

#include <cstdlib>

#include <string>

#include <math.h>

#include <fstream>

#include <vector>

using namespace std;

vector<pair<int, int> > V0;

int N = 0;

void label_check(int a)
{
    for (int i = 0; i < V0.size(); i++){
        if (a == V0[i].first)  {cout << "L" << V0[i].second << ": ";}
    }
}

int convert_string_to_decimal(string a)
{
    int ans = 0;
    int abc = 0;

    for (int i = a.length() - 1; i >= 0; i--){
        ans = ans + (a[i] - 48) * (pow(2, abc));
        abc++;
    }

    return ans;
}

int function_reverse(string imm)
{
    cout << "0x";
    int counter = 0;
    int k = 0;
    int sum = 0;

    while (k != 5){
        sum = convert_string_to_decimal(string(1, imm[4 * k]) + imm[4 * k + 1] + imm[4 * k + 2] + imm[4 * k + 3]);

        switch (sum)
        {
        case 0:
            if (counter != 0){
                cout << '0';
            }
            break;

        case 1:
            cout << '1';
            counter = 1;
            break;

        case 2:
            cout << '2';
            counter = 1;
            break;

        case 3:
            cout << '3';
            counter = 1;
            break;

        case 4:
            cout << '4';
            counter = 1;
            break;

        case 5:
            cout << '5';
            counter = 1;
            break;

        case 6:
            cout << '6';
            counter = 1;
            break;

        case 7:
            cout << '7';
            counter = 1;
            break;

        case 8:
            cout << '8';
            counter = 1;
            break;

        case 9:
            cout << '9';
            counter = 1;
            break;

        case 10:
            cout << 'a';
            counter = 1;
            break;

        case 11:
            cout << 'b';
            counter = 1;
            break;

        case 12:
            cout << 'c';
            counter = 1;
            break;

        case 13:
            cout << 'd';
            counter = 1;
            break;

        case 14:
            cout << 'e';
            counter = 1;
            break;

        case 15:
            cout << 'f';
            counter = 1;
            break;

        default:
            break;
        }

        k++;
    }

    return 0;
}

int convert_signed_string_to_decimal(string a)
{
    int ans = 0;
    int abc = 0;

    for (int i = a.length() - 1; i > 0; i--){
        ans = ans + (a[i] - 48) * (pow(2, abc));
        abc++;
    }

    ans = ans - (a[0] - 48) * (pow(2, abc));
    return ans;
}

void R_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int rs2 = convert_string_to_decimal(string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    if (funct7 == "0000000"){
        if (funct3 == "000"){
            cout << "add " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "100"){
            cout << "xor " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "110"){
            cout << "or " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "111"){
            cout << "and " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "001"){
            cout << "sll " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "101"){
            cout << "srl " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "010"){
            cout << "slt " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "011"){
            cout << "sltu " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
    }

    if (funct7 == "0100000"){
        if (funct3 == "000"){
            cout << "sub " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
        if (funct3 == "101"){
            cout << "sra " << "x" << rd << ", " << "x" << rs1 << ", " << "x" << rs2 << endl;
            return;
        }
    }

    cout << "Invalid Instruction" << endl;
}

void I1_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int imm = convert_signed_string_to_decimal(funct7 + a[6] + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    if (funct3 == "000"){
        cout << "addi " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "100"){
        cout << "xori " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "110"){
        cout << "ori " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "111"){
        cout << "andi " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "001" && funct7 == "000000"){
        imm = convert_string_to_decimal(a[6] + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);
        cout << "slli " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "101"){
        if (funct7 == "000000"){
            imm = convert_string_to_decimal(a[6] + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);
            cout << "srli " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
            return;
        }
        if (funct7 == "010000"){
            imm = convert_string_to_decimal(a[6] + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);
            cout << "srai " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
            return;
        }
    }
    if (funct3 == "010"){
        cout << "slti " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    if (funct3 == "011"){
        imm = convert_string_to_decimal(funct7 + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);
        cout << "slliu " << "x" << rd << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    cout << "Invalid instruction" << endl;
}

void I2_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int imm = convert_signed_string_to_decimal(funct7 + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    if (funct3 == "000"){
        cout << "lb " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "001"){
        cout << "lh " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "010"){
        cout << "lw " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "011"){
        cout << "ld " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "100"){
        cout << "lbu " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "101"){
        cout << "lhu " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "110"){
        cout << "lwu " << "x" << rd << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    cout << "Invalid Instruction" << endl;
}

void S_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int rs2 = convert_string_to_decimal(string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    int imm = convert_signed_string_to_decimal(funct7 + string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    if (funct3 == "000"){
        cout << "sb " << "x" << rs2 << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "001"){
        cout << "sh " << "x" << rs2 << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "010"){
        cout << "sw " << "x" << rs2 << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    if (funct3 == "011"){
        cout << "sd " << "x" << rs2 << ", " << imm << "(" << "x" << rs1 << ")" << endl;
        return;
    }
    cout << "Invalid Instruction" << endl;
}

void I3_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int imm = convert_signed_string_to_decimal(funct7 + string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    if (funct3 == "000"){
        cout << "jalr " << "x0" << ", " << "x" << rs1 << ", " << imm << endl;
        return;
    }
    cout << "Invalid Instruction" << endl;
}

void B_function(string a, int i)
{
    int imm = convert_signed_string_to_decimal(string(1, a[0]) + a[24] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + string(1, a[20]) + a[21] + a[22] + a[23] + '0');

    string funct3 = string(1, a[17]) + a[18] + a[19];

    int rs2 = convert_string_to_decimal(string(1, a[7]) + a[8] + a[9] + a[10] + a[11]);

    int rs1 = convert_string_to_decimal(string(1, a[12]) + a[13] + a[14] + a[15] + a[16]);

    if (((imm / 4 + i) >= N) || (imm / 4 + i < 0)){
        cout << "The brach is out of limits" << endl;
        return;
    }

    if (funct3 == "000"){
        cout << "beq " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;

                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }
        return;
    }
    if (funct3 == "001"){
        cout << "bne " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;
                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }
        return;
    }
    if (funct3 == "100"){
        cout << "blt " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;
                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }
        return;
    }
    if (funct3 == "101"){
        cout << "bge " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;

                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }
        return;
    }
    if (funct3 == "110"){
        cout << "bltu " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;

                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }

        return;
    }
    if (funct3 == "111"){
        cout << "bgeu " << "x" << rs1 << ", " << "x" << rs2;

        if (imm / 4 > 0){
            cout << ", L";
            int k = imm / 4;

            for (int j = 0; j < V0.size(); j++){
                if (k + i == V0[j].first){
                    cout << V0[j].second << endl;

                    return;
                }
            }

            int u = V0.size() + 1;
            cout << u << endl;
            V0.push_back(make_pair(k + i, u));
        }
        else{
            cout << ", " << imm;
            cout << endl;
        }

        return;
    }
    cout << "Invalid Instruction" << endl;
}

void J_function(string a, int i)
{
    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    int imm = convert_signed_string_to_decimal(string(1, a[0]) + string(1, a[12]) + a[13] + a[14] + a[15] + a[16] + string(1, a[17]) + a[18] + a[19] + a[11] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] + a[10] + '0');

    if (imm / 4 + i >= N || (imm / 4 + i < 0)){
        cout << "Invalid Jump" << endl;
        return;
    }

    cout << "jal " << "x" << rd;

    if (imm / 4 > 0){
        cout << ", L";
        int k = imm / 4;

        for (int j = 0; j < V0.size(); j++){
            if (k + i == V0[j].first){
                cout << V0[j].second << endl;

                return;
            }
        }

        int u = V0.size() + 1;
        cout << u << endl;
        V0.push_back(make_pair(k + i, u));
    }
    else{
        cout << ", " << imm;
        cout << endl;
    }
}

void U_function(string a)
{
    string funct7 = string(1, a[0]) + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];

    string funct3 = string(1, a[17]) + a[18] + a[19];

    string rs2 = string(1, a[7]) + a[8] + a[9] + a[10] + a[11];

    string fk = string(1, a[12]) + a[13] + a[14] + a[15] + a[16];

    string imm = funct7 + rs2 + fk + funct3;

    int rd = convert_string_to_decimal(string(1, a[20]) + a[21] + a[22] + a[23] + a[24]);

    cout << "lui " << "x" << rd << ", ";

    function_reverse(imm);

    cout << endl;
}

string convert_single_digit(char a)
{
    switch (a)
    {
    case '0':
        return "0000";
        break;

    case '1':
        return "0001";
        break;

    case '2':
        return "0010";
        break;

    case '3':
        return "0011";
        break;

    case '4':
        return "0100";
        break;

    case '5':
        return "0101";
        break;

    case '6':
        return "0110";
        break;

    case '7':
        return "0111";
        break;

    case '8':
        return "1000";
        break;

    case '9':
        return "1001";
        break;

    case 'a':
        return "1010";
        break;

    case 'b':
        return "1011";
        break;

    case 'c':
        return "1100";
        break;

    case 'd':
        return "1101";
        break;

    case 'e':
        return "1110";
        break;

    case 'f':
        return "1111";
        break;

    default:
        return "defa";
        break;
    }

    return "NULL";
}

string convert_to_binary(string a)
{
    string b[8];

    for (int i = 0; i < 8; i++){
        b[i] = convert_single_digit(a[i]);
    }

    return b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7];
}

void convert_to_assembly(string a, int i)
{
    string b = string(1, a[25]) + string(1, a[26]) + string(1, a[27]) + string(1, a[28]) + string(1, a[29]) + string(1, a[30]) + string(1, a[31]);

    if (b == "0110011"){
        R_function(a);
        return;
    }
    if (b == "0010011"){
        I1_function(a);
        return;
    }
    if (b == "0000011"){
        I2_function(a);
        return;
    }
    if (b == "1100111"){
        I3_function(a);
        return;
    }
    if (b == "0100011"){
        S_function(a);
        return;
    }
    if (b == "1100011"){
        B_function(a, i);
        return;
    }
    if (b == "1101111"){
        J_function(a, i);
        return;
    }
    if (b == "0110111"){
        U_function(a);
        return;
    }

    cout << "Invalid instruction" << endl;
}

int main()
{
    vector<string> arr;
    fstream newfile;
    string str;

    newfile.open("input.txt", ios::in);
    if (newfile.is_open()){
        while (getline(newfile, str)){
            arr.push_back(str);
            N++;
        }
    }

    newfile.close();
    vector<string> brr;

    for (int i = 0; i < N; i++){
        brr.push_back(convert_to_binary(arr[i]));
    }

    int u;
    for (int i = 0; i < N; i++){
        cout << arr[i] << " : ";
        label_check(i);
        convert_to_assembly(brr[i], i);
    }
}