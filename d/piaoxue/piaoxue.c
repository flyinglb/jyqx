inherit ROOM;
void create()
{
        set("short", "Ʈѩ¥һ¥");
        set("long", @LONG
������Ʈѩɽׯ�����ģ�����Լ�����������˺�����
����˵�������������ֱ�����������ȸ���׻�������
���ã�¥����Ʈѩɽׯ�ĳ���Ժ��ִ���úͻ����á�
����㲻��Ʈѩɽׯ���ˣ��뾡���뿪��
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	        set("exits", ([
                "east"  : __DIR__"qinglong",
                "west"  : __DIR__"baihu",
                "south"  : __DIR__"zhuque",
                "north"  : __DIR__"xuanwu",
                "southwest"  : __DIR__"piaoxie",
                "southeast"  : __DIR__"shenlong",
                "up"  : __DIR__"piaoxue2",
        ]));
        setup();
}
void init ()
{
   add_action("do_listen", "listen");
}

int do_listen(string arg)
{
   object me;
   me = this_player();

   tell_object(me,"ׯ�������Ʈѩ���ӣ�����ֹ����Υ���߸�ɱ����\n");
   message("vision",me->name(me)+"ͻȻס�㣬�ƺ��ڲ��������ʲô��\n", environment(me),me);
   return 1;
}