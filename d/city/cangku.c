// Room: /city/cangku.c

inherit ROOM;
void check();
void init();

void create()
{
	set("short", "仓库");
	set("long", @LONG
这里是一间黑黝黝的仓库，堆满了唐家的各种杂物，塞了满满一仓库。
看来你是被人拐卖到这里来的。
LONG );
	set("valid_startroom", "1");
	set("no_fight", 1);
//	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"obj/jitui" : 3,
		__DIR__"obj/jiudai" : 1,
	]));
	setup();
        call_out("check",60);
}

void init()
{
	object ob;

        ob = this_player();
	ob->set("startroom","/d/city/cangku");
	ob->set_temp("selled", 1);
}

void check()
{
        object *inv;
        int i,i1;
        inv = all_inventory(this_object());
        if( !sizeof(inv) ) {
                call_out("check",60);
                return;
        }
        for(i=0,i1=sizeof(inv);i<i1;i++) {
                if( !userp(inv[i]) ) {
                    inv[i]->move(VOID_OB);
                    destruct(inv[i]);
                }
        }
        call_out("check",60);
}
