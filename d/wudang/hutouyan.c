//Room: hutouyan.c ��ͷ��
//Date: Sep 22 1997
inherit ROOM;
void create()
{
      set("short","��ͷ��");
      set("long",@LONG
һ��޴����ʯ����ȥ����һ����ͷ���Ŵ���Ѫ������������������
�ڲ�ľ���С�
LONG);
      set("objects", ([
          __DIR__"npc/laohu" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wulaofeng",
          "southup"  : __DIR__"chaotiangong",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
