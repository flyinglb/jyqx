int do_study(string arg)
{
	string *skill_name = ({
               "strike",          //�Կ��Ϻ�ӧ
               "sword",           //�⹳˪ѩ��
               "dodge",           //�����հ���
               "throwing",        //��������
               "pixie-jian",      //ʮ��ɱһ�� sword
               "shenxing-baibian",//ǧ�ﲻ���� dodge
               "lingboweibu",     //���˷���ȥ dodge
               "shenkong-xing",   //��������� dodge
               "unarmed",         //�й������� cuff or strike or unarmed
               "taiji-jian",      //�ѽ�ϥǰ�� sword
               "parry",           //������캥
               "blade",           //����Ȱ����
               "count",           //������Ȼŵ force ��ʱ��count��
               "cuff",            //������Ϊ�� cuff or strike or unarmed
               "staff",           //�ۻ����Ⱥ�   ³������
               "claw",            //���������� cuff or strike or unarmed
               "hammer",          //���Իӽ� sword
               "hand",            //�������� force
               "array",           //ǧ���׳ʿ
               "force",           //ب�մ����� force
               "finger",          //����������   ָ��
               "club",            //��������Ӣ   ��ü��
               "whip",            //˭�������
               "taixuan-gong"     //����̫����
        });
        object me, where;
        int jing_cost, learn_pot, item;
        string skillname;

        me = this_player();
        if( !arg || ( arg != "wall" ) )
                return notify_fail("��Ҫѧʲôѽ��\n");
        if ((int)me->query("combat_exp")<50000)
                return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
        if ((int)me->query_skill("literate",1)<1)
                return notify_fail("�����˰�! ������ȥѧ���Ļ��ɡ�\n");
        jing_cost = 30 + random(me->query_int());
        if( me->query("jing") < jing_cost)
                return notify_fail("������̫���ˣ���Ϣһ��������ɡ�\n");
        me->receive_damage("jing",jing_cost);
	where = environment(me);
	switch (file_name(where))
	{
		case "/d/xiakedao/shiroom01": item = 0; break;
		case "/d/xiakedao/shiroom02": item = 1; break;
		case "/d/xiakedao/shiroom03": item = 2; break;
		case "/d/xiakedao/shiroom04": item = 3; break;
		case "/d/xiakedao/shiroom05": item = 4; break;
		case "/d/xiakedao/shiroom06": item = 5; break;
		case "/d/xiakedao/shiroom07": item = 6; break;
		case "/d/xiakedao/shiroom08": item = 7; break;
		case "/d/xiakedao/shiroom09": item = 8; break;
		case "/d/xiakedao/shiroom10": item = 9; break;
		case "/d/xiakedao/shiroom11": item = 10; break;
		case "/d/xiakedao/shiroom12": item = 11; break;
		case "/d/xiakedao/shiroom13": item = 12; break;
		case "/d/xiakedao/shiroom14": item = 13; break;
		case "/d/xiakedao/shiroom15": item = 14; break;
		case "/d/xiakedao/shiroom16": item = 15; break;
		case "/d/xiakedao/shiroom17": item = 16; break;
		case "/d/xiakedao/shiroom18": item = 17; break;
		case "/d/xiakedao/shiroom19": item = 18; break;
		case "/d/xiakedao/shiroom20": item = 19; break;
		case "/d/xiakedao/shiroom21": item = 20; break;
		case "/d/xiakedao/shiroom22": item = 21; break;
		case "/d/xiakedao/shiroom23": item = 22; break;
		case "/d/xiakedao/shiroom24": item = 23; break;
		default: break;
	}

        message_vision("$N����ר��ʯ���ϵ�ͼ����ע�͡�\n",me);

        if (me->query_skill(skill_name[item],1)<0)
        {
          write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫����ˡ�\n");
          return 1;
        }
        if (me->query_skill(skill_name[item],1)>=250)
        {
          write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
          return 1;
        }
        if (item == 4)
        {
                if ((string)me->query("gender") != "����" )
                {
                        write("���Ǳ����Ǳ�а����ͼ�ף������񹦣������Թ���\n");
                        return 1;
                }
        }
	else
        {
                if( !SKILL_D(skill_name[item])->valid_learn(me) )
                return SKILL_D(skill_name[item])->valid_learn(me);
        }
        if((int)(me->query_skill(skill_name[item],1) * 
                 me->query_skill(skill_name[item],1) * 
                 me->query_skill(skill_name[item],1)) /10 >= me->query("combat_exp"))
        {
                write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
                return 1;
        }
	learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int"))
            - (int)(me->query_skill("literate",1)/2);
	if (learn_pot > 0)
        {
                me->improve_skill(skill_name[item], learn_pot);
                write("�����ʯ��ڤ˼������һ�ᣬ�ƺ�"+CHINESE_D->chinese(skill_name[item])+"��Щ�ĵá�\n");
        }
        else write("�����ʯ��ڤ˼������һ�ᣬ���ǳɼ�̫��ƺ�ûɶ�ĵá�\n");
        return 1;
}
