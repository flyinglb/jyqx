//npc.c 宣传使者

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIY "小顽童" NOR, ({ "Xiao WanTong", "Xiao" }) );
        set("gender", "男性" );
        set("age", 16);
        set("long", "他脸上永远带着一副可爱的笑脸。\n");
        set("per", 28);
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
        set("max_neili", 9999999);
        set("max_qi", 9999999);
        set("eff_neili", 9999999);
        set("neili", 9999999);
        set("eff_qi", 9999999);
        set("qi", 9999999);
        set("max_jingli", 9999999);
        set("jingli", 9999999);
        set("max_jing", 9999999);
        set("eff_jing", 9999999);
        set("jing", 9999999);

        set("chat_chance", 3);
        set("chat_msg", ({
                (: command("es 《新金庸群侠传II》host:61.156.17.111 port:1999 欢迎您的到来。") :),
                (: command("es 《新金庸群侠传II》host:61.156.17.111 port:1999 欢迎您的到来。") :),
                (: command("es 《新金庸群侠传II》host:61.156.17.111 port:1999 欢迎您的到来。") :),
                (: command("es 《新金庸群侠传II》host:61.156.17.111 port:1999 欢迎您的到来。") :),
                (: command("es 《新金庸群侠传II》host:61.156.17.111 port:1999 欢迎您的到来。") :),
                (: command("chat 玩家请注意客店留言板和巫师公告板！！！") :),
                (: command("chat 欢迎大家去巫师会客室 post BUG ！ 我们会尽快解决！") :),
                (: command("chat* yawn Xiao") :),
        }) );
        setup();
}
