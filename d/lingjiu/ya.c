//room: ya.c
inherit ROOM;

void create()
{
  set("short","�ϻ���");
  set("long",@LONG
����ͨ��[���չ�]�ıؾ�֮·��һ��С���������۵�ͨ����翷嶥��
·���Ҳ���һ�����͵�ɽ�£�һ��ɽ�紵�������ƺ����������洫������
�Һţ�������һ�ݣ������ӿ�Ų��Ͻ��뿪���
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "westup"   : __DIR__"yan",
      "eastdown" : __DIR__"shanjiao",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
