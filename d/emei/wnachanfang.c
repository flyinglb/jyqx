//Room: wnachanfang.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
������һ�䰲�������������������е��Ӵ�������֮������������
����ط���������š���λ����ʦ̫���׼�Ů�����������붨��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"wnadian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
      setup();
      replace_program(ROOM);
}
