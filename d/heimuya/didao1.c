//room: didao1.c
inherit ROOM;

void create()
{
  set("short","�ص�");
  set("long", @LONG
����һ���쳣�ľ������ȣ��������һ�ţ������ʲô����
�����Ƶ��������棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ
����̫�ֲ��ˣ����ܺ�����Ϣ���������һ���붼����������
LONG );

  set("exits",([
      "east" : __DIR__"didao2",
      "west" : __DIR__"didao1",
      "south" : __DIR__"didao5",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
