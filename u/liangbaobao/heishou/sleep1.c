inherit ROOM;

void create()
{
  set("short","��Ϣ��");
  set("long",
"���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������
�������ֻ���м����һ����ʰ����������Ĵ󴲣�����
��������˯����\n"
     );

  set("exits",([
      "west" : __DIR__"lgong",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}

