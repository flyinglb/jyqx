// NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#define Last_Time "/data/npc/tonglao"

string ask_me();

void create()
{
        set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
        set("long",
            "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
            "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
            "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
        set("title", "���չ�����");
        set("gender", "Ů��");
        set("age", 96);
        set("nickname", HIR "Ψ�Ҷ���" NOR);
        set("shen_type",0);
        set("attitude", "peaceful");
        set("no_get", 1);

        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 2500000);
        set("score", 200000);
        set_skill("force", 200);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("hand",250);
        set_skill("strike", 250);
        set_skill("sword",150);

        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("tianyu-qijian",120);
        set_skill("yueying-wubu",200);
        set_skill("bahuang-gong", 250);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");
        create_family("���չ�",1, "��ɽ��ʦ");

        set("inquiry", ([
                "�ഺ�޼�"     : (: ask_me :),
        ]));
        set("age_count", 1);

        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}
string ask_me()
{
//      mapping fam; 
        object ob;
        
        if (  this_player()->query("combat_exp") < 100000
        ||    this_player()->query("age") < 40 )
        {
                command("say ����ʲô���������δ�ɣ�Ҳ��������˵����");
                this_object()->kill_ob(this_player());
                this_player()->kill_ob(this_object());
        }
        if( (uptime() < 48000) || (time() - atoi(read_file(Last_Time)) < 10800) )
                return "���½������Ҳ�����ҩ�������ģ����ڻ�û���ɡ�";
        if (query("age_count") < 1)
                return "���½������Ҳ�����ҩ�������ģ����ڻ�û���ɡ�";
        ob = new("/d/lingjiu/obj/age_dan");
        ob->move(this_player());
        add("age_count", -1);
        write_file(Last_Time, ""+time(), 1);
        message_vision("\nͯ��΢΢һЦ���������˽�����ʲô����Ҫ����̫���ˡ���ȡ��һ����ҩ�ݸ�$N��\n\n", this_player());
        message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"�õ�"+HIG+"����"+HIY+"��"+HIR+"�ˡ�\n"NOR, users());
        return "����������ˣ���ȥ�ɣ�";
}

void attempt_apprentice(object ob)
{
   
        if ((string)ob->query("gender")!="Ů��")
        {
                command("say ��������!");
                return;
        }
        if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
        {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
                return;
        }
        if (ob->query_con() < 30) 
        {
                command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
                return;
        }
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
        ob->set("class", "dancer");
        return;
}
void die()
{
        write_file(Last_Time, ""+time(), 1);
        ::die();
}