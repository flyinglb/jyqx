//Room: chaotiangong.c ���칬
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���칬");
      set("long",@LONG
�����ѽ��䵱������ֻ��ʯ��ֱ�ʣ�Σ�Ÿ��������Ը���������������
����
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/qingxu": 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"hutouyan",
          "south"    : __DIR__"huixianqiao",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}

