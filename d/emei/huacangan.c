//Room: huacangan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�������ǽ𶥵���Ҫ��������ģ������������������������
���������ֺ���Ƕù�̨���Ա��������֡�
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"      : __DIR__"jinding",
          "northwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"duguangtai",
          "enter"      : __DIR__"hcazhengdian",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
