//room: 
inherit ROOM;
void create()
{
  set("short","����");
  set("long", @LONG
�����ǰ׻��õĳ��ȡ�����һƬ�Ǽ��������Ӹձ�ϴ��һ����
��غ�ʬ���в��̶ġ�
LONG );
  set("exits",([
     "north" : __DIR__"baistep1",
      "south" : __DIR__"baihutang",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
