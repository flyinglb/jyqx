//Room: fushouan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ�о�����������
�أ����������ڴ������������۾���ʫ����ӽ��̾����֪Ϧ�ա����������
���������ٲ��䣬�ߴ�ʮ���ɡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhen" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "enter"     : __DIR__"lingwenge",
          "north"     : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
