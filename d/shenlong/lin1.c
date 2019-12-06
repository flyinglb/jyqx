inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
        set("short", "��ľ��");
        set("long",@LONG
����һƬ��ľ�֡��������һ���µ��Ͼ���������һƬ��ľ��(bush)
�е��ǳ��Ծ�.ǰ�����û��·,���ܵ������г������Ӳݡ�
LONG);
	set("exits", ([
	    "south" : __DIR__"haitan",
	]));
	set("item_desc", ([
	    "bush" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ�п���һ��·��(kan)��\n",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
        set("outdoors", "shenlong");
        setup();
}

void init()
{
    add_action("do_kan", "kan");
}

int do_kan ( string arg )
{
//    object ob, weapon;
    object weapon;
//    string dir;
    if( !arg || arg !="bush" ) 
         return notify_fail("��Ҫ��ʲô��\n" ) ;
	if (!objectp(weapon = this_player()->query_temp("weapon")))
		return notify_fail("�����������²��аɣ�\n");

	    message_vision(
        "$N�������,���Ź�ľ��һ���ҿ���\n", this_player());

        if(this_player()->query("neili")>100)
	{
        set("exits/north", __DIR__"lin2");
        message_vision(
        "$N�۵���������,���ڿ���һ��С·��\n", this_player());
        this_player()->add("neili",-50);
        remove_call_out("close");
        call_out("close", 20, this_object());
	}
        else	
	{
        message_vision(
        "$N�۵���������,Ҳû����һ��·����\n", this_player());
	this_player()->set("neili",0);
	}
return 1;
}

void close(object room)
{
    message("vision","��ľ�Խ�����£����,�����ָֻ���ԭ״��\n", room);
    room->delete("exits/north");
}
