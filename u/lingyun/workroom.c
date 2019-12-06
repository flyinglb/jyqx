#include <ansi.h>
inherit ROOM;

void create()
{       
set("short", HIW "凌云工作室" NOR);
set("long", @LONG
这里是凌云的工作室。整个房间布置很简单,没有豪华的设施,清清淡淡,充
满了幽雅的气息.给人一种心旷神怡的感觉。正门桌上的茶盘放着刚砌好的“铁
观音”，飘出阵阵香气。整个房间布置很简单,没有豪华的设施,清清淡淡,充满
了幽雅的气息.给人一种心旷神怡的感觉。书架(shelf)上全是好看的小说，墙上
挂着一首诗(shi)。这里一般人是不让进来的。
LONG    );
        set("valid_startroom", 1);
set("no_sleep", 1);
set("no_stear", 1);
        set("exits", ([
                "down" : "/u/lingyun/workroom1",
        ]));
        set("item_desc", ([
                "shelf" : HIR "\n这里有各门各派的武功秘籍。\n" NOR,
                "shi" : "\n\n"

HIY"            ※※※※※※※※※※※※※※※※※\n"NOR
HIY"            ※※※※　　　　　　　　　※※※※\n"NOR
HIY"            ※※※※　"HIM"缘　缘　不　但　"HIY"※※※※\n"NOR
HIY"            ※※※※　"HIM"来　尽　求　求　"HIY"※※※※\n"NOR
HIY"            ※※※※　"HIM"而　而　再　随　"HIY"※※※※\n"NOR
HIY"            ※※※※　"HIM"聚　散　聚　缘　"HIY"※※※※\n"NOR
HIY"            ※※※※　　　　　　　　　※※※※\n"NOR
HIY"            ※※※※※※※※※※※※※※※※※\n\n"NOR

        ]));
        set("objects",([
        ]));
        setup();
}
void init()
{
        object who;
        
/*
        if ( this_player()->query("id") == "lingyun" ) {
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("听说%s开始闭关，他已关闭六识与世隔绝了。", this_player()->query("name")) );
                        
                this_player()->set("channels_temp", this_player()->query("channels"));
                this_player()->set("env/no_tell", "all");
                this_player()->delete("channels");
                this_player()->save();
                write("你已经关闭六识，外面的世界与你隔离了。\n");
        }
*/
        
        
        if ( this_player()->query("id") != "lingyun" 
        && this_player()->query("id") != "ssss"
        && this_player()->query("id") != "byp"
        && this_player()->query("id") != "brave"
        && this_player()->query("id") != "linux" )
                if ( !userp(who = this_player()) || wizardp(who = this_player()) ) {
                        remove_call_out("kickout");
                        call_out("kickout",1,who);
        }
}
int kickout(object who)
{
        message_vision("凌云走了过来，一脚将$N踢到了鬼门关。\n",who);
        this_player()->move("/d/city/kedian");
        return 1;
}

/*
int valid_leave(object me, string dir)
{
        string *tunes;
        
        if( dir=="down" && this_player()->query("id") != "luckgo")
                return 1;

//         if ( !(tunes = this_player()->query("channels_temp")) )
                tunes = ({"snp", "sys", "chat", "new", "debug", "wiz", "gwiz", "gbwiz", "rumor", "party", "arch", "es",});
                
        this_player()->set("channels", this_player()->query("channels_temp") );
        this_player()->delete("env/no_tell");
        this_player()->delete("channels_temp");
        write("你慢慢的苏醒，六识从新回到你的意识里。\n");
        CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("听说%s已经出关了！", this_player()->query("name")) );
        return 1;
}
*/
