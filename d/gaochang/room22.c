// Room: /u/mei/room22.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С��");
    set("long", @LONG
��·��֪���ж������������ߣ���Щ�ط����ݱ��˻��ߣ���Щ�ط���ȫ��
ɳ����������������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������
�������ȷ�Ʈ�����ʡ�
LONG
    );
    set("exits", ([ 
  "northwest" : __DIR__"room71",
  "south" : __DIR__"room71",
  "southwest" : __DIR__"room21",
  "north" : __DIR__"room71",
  "northeast" : __DIR__"room71",
  "east" : __DIR__"room71",
  "southeast" : __DIR__"room23",
  "west" : __DIR__"room71",
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
