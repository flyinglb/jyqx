inherit ROOM;

void create()
{
  set("short","��������Ϣ��");
  set("long",
"�����Ǽ���Ϣ�ң������������Ŵ󴲡�
������˯���ǳ������û���ܴ��š�\n"
     );

  set("exits",([
      "west" : __DIR__"xwdian",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}