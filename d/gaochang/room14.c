// Room: /u/mei/room14.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "��Į��ɳ");
        set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸������������������
�ķ�������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�
�·�ֻʣ����һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
        );
        set("no_new_clean_up", 0);
        set("exits", ([ /* sizeof() == 8 */
  "south" : __DIR__"room14",
  "southwest" : __DIR__"room14",
  "north" : __DIR__"room14",
  "northeast" : __DIR__"room14",
  "east" : __DIR__"room14",
  "southeast" : __DIR__"room9",
  "west" : __DIR__"room14",
  "northwest" : __DIR__"room14",
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
int valid_leave(object me, string dir)
{
        int current_water;
        current_water = (int)me->query("water");
        if (!current_water) return 1;
        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }
        if (current_water>20) {
            me->set("water",current_water-20);
        }

    return 1;
}
