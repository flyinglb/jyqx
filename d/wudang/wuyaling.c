//Room: wuyaling.c ��ѻ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","��ѻ��");
      set("long",@LONG
����һ�����ļ��룬����������һ���������������ƶ�䣬ȽȽ������ɽ
�����������Ϯ��������ֻ��ѻ�������Ƽʣ��ڰ׷�����ε����ۡ�
LONG);
      set("objects", ([
                __DIR__"npc/wuya" : 5,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"langmeiyuan",
          "southup"  : __DIR__"sanlaofeng",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
