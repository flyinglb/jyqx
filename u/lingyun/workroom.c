#include <ansi.h>
inherit ROOM;

void create()
{       
set("short", HIW "���ƹ�����" NOR);
set("long", @LONG
���������ƵĹ����ҡ��������䲼�úܼ�,û�к�������ʩ,���嵭��,��
�������ŵ���Ϣ.����һ���Ŀ������ĸо����������ϵĲ��̷��Ÿ����õġ���
��������Ʈ�������������������䲼�úܼ�,û�к�������ʩ,���嵭��,����
�����ŵ���Ϣ.����һ���Ŀ������ĸо������(shelf)��ȫ�Ǻÿ���С˵��ǽ��
����һ��ʫ(shi)������һ�����ǲ��ý����ġ�
LONG    );
        set("valid_startroom", 1);
set("no_sleep", 1);
set("no_stear", 1);
        set("exits", ([
                "down" : "/u/lingyun/workroom1",
        ]));
        set("item_desc", ([
                "shelf" : HIR "\n�����и��Ÿ��ɵ��书�ؼ���\n" NOR,
                "shi" : "\n\n"

HIY"            ����������������������������������\n"NOR
HIY"            ����������������������������������\n"NOR
HIY"            ����������"HIM"Ե��Ե����������"HIY"��������\n"NOR
HIY"            ����������"HIM"������������"HIY"��������\n"NOR
HIY"            ����������"HIM"���������١��桡"HIY"��������\n"NOR
HIY"            ����������"HIM"�ۡ�ɢ���ۡ�Ե��"HIY"��������\n"NOR
HIY"            ����������������������������������\n"NOR
HIY"            ����������������������������������\n\n"NOR

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
                        sprintf("��˵%s��ʼ�չأ����ѹر���ʶ���������ˡ�", this_player()->query("name")) );
                        
                this_player()->set("channels_temp", this_player()->query("channels"));
                this_player()->set("env/no_tell", "all");
                this_player()->delete("channels");
                this_player()->save();
                write("���Ѿ��ر���ʶ�������������������ˡ�\n");
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
        message_vision("�������˹�����һ�Ž�$N�ߵ��˹��Źء�\n",who);
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
        write("�����������ѣ���ʶ���»ص������ʶ�\n");
        CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("��˵%s�Ѿ������ˣ�", this_player()->query("name")) );
        return 1;
}
*/
