//room: didao2.c
inherit ROOM;

void create()
{
  set("short","�ص�");
  set("long", @LONG
��������һ���ص�������������̫ƽ�����������Եļ�յ��
�ƣ��谵�綹���ǿ���ȥǰ�����й�������Ҫ�Ǿ��ú��£�����
��ͷ���ǿ��Եģ��������쳣���ľ�ȴҲ���󼤷�����ĺ����ģ�
���ɷ����ֺ�����أ����������ɼѡ�
LONG );

  set("exits",([
         "down" : "/d/city/guangchang",
      "west" : __DIR__"didao1", 
      "south" : __DIR__"didao5",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
