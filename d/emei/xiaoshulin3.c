//Room: xiaoshulin3.c С����
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","С����");
      set("long",@LONG
���Ƕ���ɽ�𶥻��������һƬС���֡�����û��·����������ϡ��Щ��
�����ƺ��������߹���
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "southeast" : __DIR__"xiaoshulin4", 
          "north"     : __DIR__"xiaoshulin2", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
