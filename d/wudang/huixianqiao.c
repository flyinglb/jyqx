//Room: huixianqiao.c ������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
���������ƽ��һ��ɽ������������һ��խխ��ľ�ź��ڽ��ϣ�ֻ��һ��
������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"chaotiangong",
          "south"    : __DIR__"toutiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
