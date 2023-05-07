#include <iostream>
#include <string>
#include <stack>
#include <list>
using namespace std;

//洛谷 P1175 表达式的转换

char op_priority_table[255][255];

void init_op_priority_table() {
    char ops[9] = "+-*/^()#";
    int basic_priority[8] = { 1,1,2,2,3,4,0,-1 };
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            int diff = basic_priority[i] - basic_priority[j];
            if (diff >= 0) {
                op_priority_table[ops[i]][ops[j]] = '>';
            } else if (diff < 0) {
                op_priority_table[ops[i]][ops[j]] = '<';
            }
        }
    }
	for (int j = 0; j < 6; ++j) {
        op_priority_table['('][ops[j]] = '<';
        op_priority_table['#'][ops[j]] = '<';
	}
    op_priority_table['#']['('] = '<';
    op_priority_table['('][')'] = '=';
    op_priority_table[')'][')'] = '>';
    op_priority_table['^']['^'] = '<';
  /*  printf(("  "));
    for (int i = 0; i < 7; ++i) {
        printf("%c ", ops[i]);
    }
    putchar('\n');
    for (int i = 0; i < 7; ++i) {
        printf("%c ", ops[i]);
        for (int j = 0; j < 7; ++j) {
            printf("%c ", op_priority_table[ops[i]][ops[j]]);
        }
        putchar('\n');
    }*/
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}


struct Notation {
    union
    {
        int opnd;
        char optr;
    };
    bool isOperator;
};

void getRPN(string& expr, list<Notation>& rpnList) {
    stack<char> operators;
    operators.push('#'); //
    for (char ch: expr) {
        if (isDigit(ch)) {
            rpnList.push_back({ ch - '0',false });
        } else switch (op_priority_table[operators.top()][ch]) {
        case '<':
            operators.push(ch);
            break;
        case '>':
            //弹出运算符并输出,直到栈顶运算符相对优先级小于当前运算符
            while (1) {
                char op = operators.top();
                if (op_priority_table[op][ch] == '<') {
                    operators.push(ch);
                    break;
                } else if (op_priority_table[op][ch] == '=') {
                    operators.pop();            //特殊情况，ch为')',op为'('，此时两运算符相对优先级相同,两括号抵消
                    break;
                } else {
					operators.pop();
					rpnList.push_back({ op,true });
                }
            }
            break;
        case '=':
            operators.pop();
            break;
        }
    }
    while (operators.top() != '#') {
        char op = operators.top();
        operators.pop();
        rpnList.push_back({ op,true });
    }
}


int operate(int oprd1, int oprd2, char optr) {
    switch (optr)
    {
    case '+':
        return oprd1 + oprd2;
    case '-':
        return oprd1 - oprd2;
    case '*':
        return oprd1 * oprd2;
    case '/':
        return oprd1 / oprd2;
    case '^':
        int res = oprd1;
        for (int i = 1; i <= oprd2 - 1; ++i) {
            res *= oprd1;
        }
        return res;
    }
}

void printRPN(list<Notation>::iterator iter,list<Notation>::iterator endIter) {
    while (iter != endIter) {
        if (iter->isOperator) {
            cout << iter->optr << " ";
        } else {
            cout << iter->opnd << " ";
        }
        ++iter;
    }
}

void printOperands(list<int>& operands) {
	for (int operand : operands) {
		cout << operand << " ";
	}
}

void operateRPN(list<Notation>& rpnList) {
    list<int> operands;
    printRPN(rpnList.begin(), rpnList.end());
    cout << "\n";
    for (list<Notation>::iterator iter = rpnList.begin(); iter != rpnList.end();) {
        if (iter->isOperator) {
            int opnd2 = operands.back();
            operands.pop_back();
            int opnd1 = operands.back();
            operands.pop_back();
            operands.push_back(operate(opnd1, opnd2, iter->optr));
            printOperands(operands);
            printRPN(++iter, rpnList.end());
            cout << "\n";
        } else {
            operands.push_back(iter->opnd);
            ++iter;
        }
    }
}


int main()
{
    init_op_priority_table();
    string expr;
    cin >> expr;
    list<Notation> rpnList;
    getRPN(expr, rpnList);
    operateRPN(rpnList);
}
