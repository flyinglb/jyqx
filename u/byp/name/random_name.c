// random_name.c
// npc �������

//mapping man_name1 ����һ
//mapping man_name2 ������
//mapping woman_name1 Ů��һ
//mapping woman_name2 Ů����
//string* title ��� title
// ����   ���� ������(Dai shitao)

mapping surname = ([
"��":"zhao", "Ǯ":"qian", "��":"sun",  "��":"li",   "��":"zhou",
"��":"wu",   "֣":"zhen", "��":"wang", "��":"feng", "��":"chen",
"��":"zhu",  "��":"wei",  "��":"jiang","��":"shen", "��":"han",
"��":"yang", "��":"zhu",  "��":"qin",  "��":"you",  "��":"xu",
"��":"he",   "��":"lv",   "ʩ":"shi",  "��":"zhang","��":"kong",
"��":"cao",  "��":"yan",  "��":"hua",  "��":"jin",  "κ":"wei",
"��":"tao",  "��":"jiang","��":"qi",   "л":"xie",  "��":"zhou",
"��":"yu",   "��":"bo",   "ˮ":"shui", "�":"dou",  "��":"zhang",
"��":"yun",  "��":"su",   "��":"pan",  "��":"ge",   "��":"xi",
"��":"fan",  "��":"peng", "��":"lang", "³":"lu",   "Τ":"wei",
"��":"chang","��":"ma",   "��":"miao", "��":"feng", "��":"hua",
"��":"fang", "ɵ":"sha",  "��":"ren",  "Ԭ":"yuan", "��":"liu",
"��":"deng", "��":"bao",  "ʷ":"shi",  "��":"tang", "��":"fei",
"��":"lian", "�":"chen", "Ѧ":"xue",  "��":"lei",  "��":"he",
"��":"ni",   "��":"tang", "��":"teng", "��":"yin",  "��":"luo",
"��":"hua",  "��":"hao",  "��":"wu",   "��":"an",   "��":"chang",
"��":"le",   "��":"dai",  "ʱ":"shi",  "��":"fu",   "Ƥ":"pi",
"��":"bian", "��":"qi",   "��":"kang", "��":"wu",   "��":"yu",
"Ԫ":"yuan", "��":"po",   "��":"gu",   "ӯ":"ying", "ƽ":"ping",
"��":"huang","��":"he",   "��":"mu",   "Ф":"xiao", "��":"yi",
"Ҧ":"yao",  "��":"shao", "տ":"zhan", "��":"wang", "��":"qi",
"ë":"mao",  "��":"yu",   "��":"di",   "��":"mi",   "��":"bei",
"��":"ming", "��":"zang", "��":"ji",   "��":"fu",   "��":"cheng",
"��":"dai",  "̸":"tan",  "��":"song", "é":"mao",  "��":"pang",
"��":"xiong","��":"ji",   "��":"su",   "��":"qu",   "��":"xiang",
"ף":"zhu",  "��":"dong", "��":"liang","��":"fan",  "��":"hu",
"��":"ling", "��":"huo",  "��":"yu",   "��":"wan",  "֧":"zhi",
"��":"ke",   "��":"jiu",  "��":"guan", "¬":"lu",   "Ӣ":"ying",
"��":"qiu",  "��":"hou",  "��":"yue",  "˧":"shuai","ŷ":"ou",
"��":"gou",  "��":"kang", "��":"kuang","��":"hou",  "��":"you",
"��":"qin",  "��":"shang","Ĳ":"mou",  "��":"she",  "��":"er",
"ī":"mo",   "��":"ha",   "��":"qiao", "��":"nian", "��":"ai",
"��":"yang", "١":"dong", "��":"di",   "��":"wu",   "��":"yan",
"��":"fu",   "��":"kai",  "��":"zong", "��":"zong", "��":"lin",
"ʯ":"shi",  "��":"guo",  "��":"zuo",
"˾��":"sima",      "�Ϲ�":"shangguan", "ŷ��":"ouyang",
"�ĺ�":"xiahou",    "���":"zhuge",     "����":"wenren",
"����":"dongfang",  "����":"helian",    "�ʸ�":"huangpu",
"ξ��":"weichi",    "����":"gongyang",  "�̨":"zhantai",
"����":"gongye",    "����":"zongzheng", "���":"puyang",
"����":"chunyu",    "����":"shanyu",    "̫��":"taishu",
"����":"shentu",    "����":"gongsun",   "����":"zongsun",
"ԯ��":"yuanxuan",  "���":"linghu",    "����":"zhongli",
"����":"yuwen",     "����":"changsun",  "Ļ��":"murong",
"˾ͽ":"situ",      "ʦ��":"shikong",   "��":"zhuangkong",
"��ľ":"duanmu",    "����":"wuma",      "����":"gongxi",
"���":"qidiao",    "����":"lezheng",   "����":"xiangsi",
"����":"gongliang", "��ֺ":"tuozhi",    "�й�":"jiagu",
"�׸�":"zaifu",     "����":"guliang",   "����":"chujing",
"�ַ�":"yanfa",     "��۳":"ruye",      "Ϳ��":"tuqin",
"��ǧ":"duanqian",  "����":"baili",     "����":"dongguo",
"�Ϲ�":"nanguo",    "����":"huyan",     "�麣":"guihai",
"����":"yangshe",   "΢��":"weisheng",  "����":"liangqiu",
"����":"zuoqiu",    "����":"gongmen",   "����":"ximen",
"����":"baisheng",  "�Ϲ�":"nangong",
]);

mapping man_name1 = ([
"��":"zhong","Т":"xiao", "��":"li",   "��":"yi",
"��":"zhi",  "��":"yong", "��":"ren",  "��":"kuang",
"��":"xian", "��":"ling", "��":"fu",   "»":"lu",
"��":"da",   "С":"xiao", "��":"xiao", "��":"gao",
"��":"ke",   "��":"a",    "��":"jin",  "��":"shi",
"��":"ke",   "��":"shu",  "֮":"zhi",  "��":"gong",
"��":"fu",   "ʱ":"shi",  "��":"ruo",  "��":"qing",
"��":"wen",  "��":"wu",   "��":"duo",  "��":"cai",
"��":"zhang","��":"zi",   "��":"yong", "��":"you",
"��":"zi",   "��":"ren",  "Ϊ":"wei",  "��":"tie",
]);

mapping man_name2 = ([
"��":"ba",   "��":"bai",  "��":"ban",  "��":"bin",
"��":"bin",  "��":"chang","��":"chao", "��":"cheng",
"��":"chuan","��":"ding", "��":"ding", "��":"dou",
"��":"fa",   "��":"fei",  "��":"feng", "��":"feng",
"��":"gang", "�":"gang", "��":"guan", "��":"guang",
"��":"hai",  "��":"hu",   "��":"hua",  "��":"hao",
"��":"hong", "��":"qi",   "��":"jian", "��":"jian",
"��":"jian", "��":"jiang","��":"jin",  "��":"jie",
"��":"jun",  "��":"kang", "��":"liang","��":"lin",
"��":"min",  "��":"ming", "��":"ming", "��":"ning",
"��":"pei",  "��":"qi",   "ǿ":"qiang","��":"rong",
"ɽ":"shan", "̩":"tai",  "��":"tao",  "ͦ":"ting",
"ΰ":"wei",  "��":"xi",   "��":"xiang","��":"xiong",
"��":"xu",   "��":"yi",   "�":"yu",   "��":"yu",
"��":"yu",   "��":"yue",  "��":"zhou",
]);

mapping woman_name1 = ([
"��":"ai",   "��":"chun", "��":"dan",  "��":"fang",
"��":"fen",  "��":"feng", "��":"gu",   "��":"hong",
"��":"hong", "��":"jiao", "��":"juan", "��":"ju",
"��":"lan",  "�":"lan",  "��":"li",   "��":"li",
"��":"lian", "��":"ling", "��":"lin",  "��":"na",
"��":"qin",  "��":"qin",  "ٻ":"qian", "Ƽ":"ping",
"��":"ting", "ϼ":"xia",  "��":"xiang","��":"yan",
"��":"yan",  "Ӣ":"ying", "��":"ying", "��":"yu",
"��":"zhen", "��":"zhu",
]);

mapping woman_name2 = ([
"��":"ai",   "��":"chun", "��":"dan",  "��":"fang",
"��":"fen",  "��":"feng", "��":"gu",   "��":"hong",
"��":"hong", "��":"jiao", "��":"juan", "��":"ju",
"��":"lan",  "�":"lan",  "��":"li",   "��":"li",
"��":"lian", "��":"ling", "��":"lin",  "��":"na",
"��":"qin",  "��":"qin",  "ٻ":"qian", "Ƽ":"ping",
"��":"ting", "ϼ":"xia",  "��":"xiang","��":"yan",
"��":"yan",  "Ӣ":"ying", "��":"ying", "��":"yu",
"��":"zhen", "��":"zhu",
]);

mapping man_name()
{
        mapping name;
        string* sn = keys(surname);
        string* n1 = keys(man_name1);
        string* n2 = keys(man_name2);
        int i, j, k;
        i = random(sizeof(sn));
        j = random(sizeof(n1));
        k = random(sizeof(n2));
        
        name = ([
                "name" : sn[i]+n1[j]+n2[k],
                "id" : ({surname[sn[i]]+" "+man_name1[n1[j]]+man_name2[n2[k]],
                surname[sn[i]]+man_name1[n1[j]]+man_name2[n2[k]],
                surname[sn[i]], man_name1[n1[j]]+man_name2[n2[k]],}),
        ]);
        return name;
}

//��Ϊû�� woman_name1 �б��˺����޷�ʹ��
mapping woman_name()
{
        mapping name;
        string* sn = keys(surname);
        string* n1 = keys(woman_name1);
        string* n2 = keys(woman_name2);
        int i, j, k;
        i = random(sizeof(sn));
        j = random(sizeof(n1));
        k = random(sizeof(n2));
        
        name = ([
                "name" : sn[i]+n1[j]+n2[k],
                "id" : ({surname[sn[i]]+" "+woman_name1[n1[j]]+woman_name2[n2[k]],
                surname[sn[i]]+woman_name1[n1[j]]+woman_name2[n2[k]],
                surname[sn[i]], woman_name1[n1[j]]+woman_name2[n2[k]],}),
        ]);
        return name;
}
