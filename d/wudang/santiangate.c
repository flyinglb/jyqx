//Room: santiangate.c ������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����ǵ�ɽʯ�׵ľ�ͷ�������š����������߾����䵱�����ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
