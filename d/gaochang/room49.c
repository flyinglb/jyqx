// Room: /d/gaochang/room49.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
Խ������Խ�ܣ�������������������Ҳ��ð߰ߵ�㡣é�ݽ��񣬹�ľ������
·�����𡣴����ķ�ҲԽ�������䳱ʪ��Զ�����ֵ�������м�ֻ������ͺӥ����
��˺���ѷεĽ���������ë���Ȼ��
LONG
);
        set("outdoors", "room49");
        set("objects", ([ 
        __DIR__"npc/ying" : 4,
]));
        set("exits", ([ 
  "westup" : __DIR__"room50",
  "east" : __DIR__"room48",
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
    if (!present("tu ying",this_object())){
    ob=new( __DIR__"npc/tuying");
    ob->move(this_object());
    message("vision","һ����ӰͻȻ���������\n",this_object());
    }
}
