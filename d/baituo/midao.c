//midao.c
inherit ROOM;

void create()
{
  set("short","�ܵ�");
  set("long","��������ڵ��ܵ����������ɽ����Ϊ��ֱ����ԭ������ġ�\n"); 
  set("exits" , ([
    "east" : "/d/city/beidajie1",
      ]));
//  set("objects",([
//     __DIR__"obj/shenshe" : 1 ,
//    ]));
//  set("no_clean_up", 0);
 setup();
}
/*
void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{

	object me = this_player();
	object ob;
	if ((arg != "shenshe") || !arg)
	  return notify_fail("��Ҫ��ʲô��\n");
	if(!objectp(ob=present("shenshe",environment(me))))
	  return notify_fail("����û�С���·���ߡ�.\n");
	if(me->query("family/family_name") != "����ɽ��")
	  return notify_fail("����ֻ�а���ɽ�ɵ��Ӳ���ʹ���ġ���·���ߡ�.\n");
	ob->move(me);
	message_vision("$N������·���ߡ����ڻ��\n",me);
	return 1;
}
*/
