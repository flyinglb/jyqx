// tyroad13.c ��԰С·
// by Marz 

inherit ROOM;
#include "feng.h"
string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
                                
void do_tao();
int do_zhai(string arg);
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "��԰");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰��С·�ϡ�������������(tree)������
ʢ���ŷۺ���һ�������һƬ���������ߡ���ʱ���۷䡸���ˡ��طɹ�����ʧ
���ڻ����У���ֻ���������ϻ���׷���ţ�ߴߴ�������������ӡ�Զ���Ǹ߸�
��������(feng)��
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"gyroad1",
		"west" : __DIR__"tyroad12",
	]));
	
	set("item_desc", ([
        	"feng" : (:look_feng:),
		"tree" : 
"����һƬ���֣����������ˮ���ң������˹����Ӷ��������ˡ�\n"
	 ]));
	set("objects", ([
 		CLASS_D("wudang") + "/shouyuan" : 1,
		__DIR__"npc/"+npcs[i] : 1
	]));
	set("taocount",2);
//	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("look_feng", "look");
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{       object tao;
         if( !arg || arg=="" ) {
message_vision("����ժʲô��\n", this_player());
return 1;
}
        if( arg=="tao"||arg=="taozi" ) {
            if(query("taocount") > 0){
                message_vision(
       "$N������ժ��һ����͸��ˮ���ҡ�\n"
                        , this_player());
                tao = new(__DIR__"obj/mitao");
                tao->move(this_player());
		add("taocount",-1);
                return 1;
		}else
        message_vision(
	"����ô�ż�ѽ���һ�û���ء�\n" , this_player());
	remove_call_out("do_tao");
        call_out("do_tao",60);
	return 1;	     
                }
        return 0;
}
void do_tao()
{
	set("taocount",2);
}
