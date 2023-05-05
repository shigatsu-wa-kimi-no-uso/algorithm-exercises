#include <iostream>

//P1238走迷宫

struct Environment {
	int posy;
	int posx;
	int trydir;
};


using Elem_t = Environment;

struct Stack {
    Elem_t* pTop;
    Elem_t* pBase;
    int size;
};

enum Status {
    OK,
    ERROR
};

Status InitStack(Stack& s, int size) {
    Elem_t* buf = nullptr;
    buf = new Elem_t[size];
    if (buf == nullptr) {
        return ERROR;
    }
    s = { buf, buf ,size };
    return OK;
}

Status DestroyStack(Stack& s) {
    delete[] s.pBase;
	return OK;
}

Status Push(Stack& s, const Elem_t& e) {
    if (s.pTop == &s.pBase[s.size]) {
        return ERROR;
    }
    *s.pTop = e;
    s.pTop++;
    return OK;
}

Status Pop(Stack& s,Elem_t& e) {
    if (s.pTop == s.pBase) {
        return ERROR;
    }
    s.pTop--;
    e = *s.pTop;
    return OK;
}

Status Pop(Stack& s) {
	if (s.pTop == s.pBase) {
		return ERROR;
	}
	s.pTop--;
	return OK;
}


Status Top(Stack& s, Elem_t& e) {
    if (s.pTop != s.pBase) {
        e = *(s.pTop - 1);
        return OK;
    } else {
        return ERROR;
    }
}

Status Top(Stack& s, Elem_t** e) {
	if (s.pTop != s.pBase) {
		*e = s.pTop - 1;
		return OK;
	} else {
		return ERROR;
	}
}

bool IsEmpty(Stack& s) {
    return s.pTop == s.pBase;
}

bool IsFull(Stack& s) {
    return s.pTop == &s.pBase[s.size];
}

/*
//迷宫,1为路,0为墙
static int map[24][24] = {
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,1,0,1,0},
    {0,1,1,1,1,1,1,0},
    {0,0,0,1,1,1,0,0},
    {0,1,1,1,1,1,0,0},
    {0,1,1,1,0,1,1,0},
    {0,0,0,0,0,0,0,0}
};*/
static int map[24][24] = { 0 };
static int dirx[8] = { -1,0,1,0 };
static int diry[8] = { 0,-1,0,1 };



void PrintStackTrace(Stack& s) {
    Elem_t* p;
    for (p = s.pBase; p != s.pTop-1; ++p) {
        printf("(%d,%d)->", p->posy, p->posx);
    }
    printf("(%d,%d)\n", p->posy, p->posx);
}

bool ok = false;

void TraverseMaze_DFS(int (*map)[24],int*dirx,int* diry,int startx,int starty,int endx,int endy) {
	Stack stack;
	InitStack(stack, 104857600);
	//DFS求迷宫路径
	Push(stack, { starty,startx ,-1 });  //模拟函数调用
	Environment* env = nullptr;
	while (!IsEmpty(stack)) {
		Top(stack, &env);    //读取环境
		if (env->posy == endy && env->posx == endx) {
			PrintStackTrace(stack); //打印栈环境,相当于打印路径
			Pop(stack);
            ok = true;
			continue;
		}

		//防止往回走
		map[env->posy][env->posx] = 0;
		//修改的值会影响stack中的值
		while (1) {
			++env->trydir;
			if (env->trydir == 4) {
				Pop(stack);    //模拟函数返回
				map[env->posy][env->posx] = 1;
				break;
			}
			int nexty = env->posy + diry[env->trydir];
			int nextx = env->posx + dirx[env->trydir];
			int next = map[nexty][nextx];
			if (next == 1) { //如果路可走
				Push(stack, { nexty,nextx,-1 });  //模拟函数调用
				break;      //跳出当前过程,到新过程中去
			}
		}
	}
	DestroyStack(stack);
}

int main()
{
    using namespace std;
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    int starty = 1, startx = 1, endx = 6, endy = 5;
    cin >> starty >> startx >> endy >> endx;
    /**
    //起点终点
    int starty = 1, startx = 1, endx = 6, endy = 5;*/
    TraverseMaze_DFS(map, dirx, diry, startx, starty, endx, endy);
    if (!ok) {
        cout << "-1";
    }
    return 0;
}
