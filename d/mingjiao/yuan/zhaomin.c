// zhao.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("����", ({ "zhao min", "min", "zhao"}));
        set("title", HIY "��Ԫ��������" NOR);
        set("long",
"��������ϼ����ɫ������ʮ������֮�У�����������Ӣ�������ֺ�̬��ͬ
ʱӺ�ݻ�������һ������֮�£�������Ȼ�𾴣����ұ��ӡ�\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 30);
        set("str", 15);
        set("int", 25);
        set("con", 25);
        set("dex", 30);

        set("max_qi", 500);
        set("max_jing", 200);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 50);
        set("combat_exp", 50000+random(10000));
        set("score", 20000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("liangyi-jian", 80);
        set_skill("huifeng-jian", 80);
        set_skill("taiji-shengong", 90);
        set_skill("changquan", 80);
        set_skill("lingxu-bu", 80);
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
        map_skill("unarmed", "changquan");
	set_temp("is_riding", HIM"������"NOR);
	set("chat_chance", 30);
	set("chat_msg", ({
		(: random_move :)
	}) );
        set("inquiry", ([
            "���޼�" :  "�Ź���Զ�����أ���֪�������ɺã����䴺�������к��£�\n",
            "���콣" :  "����Ϊ���������\n",
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/female2-cloth")->wear();
        add_money("gold",1);
}
