//Room: toutiangate.c ͷ����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ͷ����");
      set("long",@LONG
ֻ����ʯ������ͨ��ɽ�ۣ�һ��ʯ����д�š�ͷ���š��������֣�������
���䵱�������������㡣
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"huixianqiao",
          "southup"  : __DIR__"ertiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
