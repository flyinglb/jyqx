// Room: /u/mei/room26.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�߲�����");
        set("long", @LONG
һ����ȥ���߸߰����ķ����α��۴Σ�������Ϣȫ�ޣ�����ȸ�����֮
����˿�����š�������ؿɲ��ľ��󣬼ž�������ʹ��������Ҳ���Ҵ���һ
�ڡ�һƬ�ž�֮�У�Զ����Ȼ�������������ơ�
LONG
        );
        set("outdoors", "room26");
        set("exits", ([ 
  "east" : __DIR__"room25",
  "west" : __DIR__"room27",
  "north" : __DIR__"room28",
]));

        setup();
}
void init()
{
    if ( userp( this_player() ) )
    call_out("kill_user",1,this_player());
}
int kill_user(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
    if (!present("wolf",this_object())){
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    message("vision","������ӰͻȻ����������\n",this_object());
    }
}
