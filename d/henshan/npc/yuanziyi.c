// yuanziyi.c Ԭ����

#include <command.h>
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("Ԭ����", ({ "yuan ziyi","ziyi","yuan"}));
        set("long",
                "���Ƕ�����һ�����ݼ��ߵ�����Ĺ���ͽ�ܡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "��һ·��ȥ��ʦ�����˺ü������š�\n");
        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("title", RED"�żҰ�����"HIG"������"NOR);
        set("class", "bonze");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "���"    : "�Һͺ����Ͼ�û��Ե�ݵġ�",
                "����"    : "�Ҿ�ϲ�������ţ�",
        ]));
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 1000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jingli", 1000);
        set("max_jingli", 1000);

        set("combat_exp", 1500000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("finger", 150);
        set_skill("parry", 150);
        set_skill("unarmed", 150);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("claw", 150);
        set_skill("literate", 150);
        set_skill("mahayana", 150);
        set_skill("jinding-zhang", 150);
        set_skill("jiuyin-baiguzhao", 150);
        set_skill("tiangang-zhi", 150);
        set_skill("huifeng-jian", 150);
        set_skill("zhutian-bu", 150);
        set_skill("linji-zhuang", 150);
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
}
/*
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        command("say ��������������Ϣ�����������");
        command("kick "+ob->query("id"));
        ob->move("/d/henshan/hsroad6");
        return;
}
*/
