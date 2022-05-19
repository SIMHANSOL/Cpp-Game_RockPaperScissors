#include < iostream >
#include < conio.h >
#include < time.h >
#include < windows.h >

// 범위 안의 랜덤한 정수를 반환합니다.
int random_range(int _x1, int _x2)
{
  int range = (_x2 - _x1) + 1;
  return (rand() % range) + _x1;
}

int main()
{
  srand(time(NULL));                 // 컴퓨터 시간을 시드 값으로 사용합니다.
  int turn = 0;                      // 턴.
  int turn_max = random_range(3, 5); // 최대 턴.
  int p_score = 0;                   // 플레이어 점수.
  int c_score = 0;                   // 컴퓨터 점수.
  for (; turn < turn_max; turn++)
  {
  main_loop:
    printf("현재 턴: %d / %d\n현재 점수\n(플레이어: %d, 컴퓨터: %d)", turn + 1, turn_max, p_score, c_score);
    printf("\n-------------------------------\n\n");
    printf("컴퓨터: 가위 바위....\n\n");
    printf("무엇을 내시겠습니까?\n[1: 가위]\n[2: 바위]\n[3: 보]\n\n");
    int p_select = 0; // 플레이어 선택.
    int c_select = 1; // 컴퓨터 선택.
    char *p_string = new char[5];
    char *c_string = new char[5];
    char *result = new char[12];
    switch (_getch())
    {
    case 49:
      p_select = 1;
      break;
    case 50:
      p_select = 2;
      break;
    case 51:
      p_select = 3;
      break;
    }
    c_select = random_range(1, 3);
    switch (p_select)
    {
    case 0:
      printf("컴퓨터: 제대로 안 내고 뭐해? 다시 하자.\n\n");
      Sleep(1000);
      system("cls");
      goto main_loop;
      break;
    case 1:
      p_string = "가위";
      break;
    case 2:
      p_string = "바위";
      break;
    case 3:
      p_string = "보";
      break;
    }
    switch (c_select)
    {
    case 1:
      c_string = "가위";
      break;
    case 2:
      c_string = "바위";
      break;
    case 3:
      c_string = "보";
      break;
    }
    switch (p_select)
    {
    case 1:
      switch (c_select)
      {
      case 1:
        result = "비겼네.";
        break;
      case 2:
        result = "너가 졌네.";
        c_score++;
        break;
      case 3:
        result = "너가 이겼네.";
        p_score++;
        break;
      }
      break;
    case 2:
      switch (c_select)
      {
      case 1:
        result = "너가 이겼네.";
        p_score++;
        break;
      case 2:
        result = "비겼네.";
        break;
      case 3:
        result = "너가 졌네.";
        c_score++;
        break;
      }
      break;
    case 3:
      switch (c_select)
      {
      case 1:
        result = "너가 졌네.";
        c_score++;
        break;
      case 2:
        result = "너가 이겼네.";
        p_score++;
        break;
      case 3:
        result = "비겼네.";
        break;
      }
      break;
    }
    printf("컴퓨터: 보!!!\n\n");
    printf("넌 %s를 냈는데. 난 %s를 냈구나. %s\n\n", p_string, c_string, result);
    printf("[플레이어: %s], [컴퓨터: %s]\n\n", p_string, c_string);
    Sleep(4000);
    system("cls");
  }
  turn--;
  printf("현재 턴: %d / %d\n현재 점수\n(플레이어: %d, 컴퓨터: %d)", turn + 1, turn_max, p_score, c_score);
  printf("\n-------------------------------\n\n");
  if (p_score == c_score)
  {
    printf("컴퓨터: 동점이네! 우리 서로 잘 맞나봐.");
  }
  else if (p_score > c_score)
  {
    printf("컴퓨터: 너가 이겼네. 너 꽤 잘하잖아. 부럽다.");
  }
  else if (c_score > p_score)
  {
    printf("컴퓨터: 내가 이겼네! 오늘 운이 좋았나봐.");
  }
  Sleep(4000);
  system("cls");
  printf("컴퓨터: 함께 해서 즐거웠어!\n컴퓨터: 다음에 또 같이 하자!\n\n");
}