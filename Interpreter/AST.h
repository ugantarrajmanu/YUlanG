typedef enum {
        Program,
        VariableDeclaration,
        Assignment,
        BinaryExpression,
        Identifier,
        Literal,
        IfStatement,
        ForStatement,
        BlockStatement,
        Body,
        PrintStatement,
    } NodeType;

    typedef struct ASTNode{
        NodeType type;
        union {
            struct{
                char* value;
            } Identifier;

            struct {
                int value;
            } Literal;

            struct {
                char* kind;
                struct ASTNode* id;
                struct ASTNode* init;
            } VariableDeclaration;

            struct {
                char* kind;
                struct ASTNode* id;
                struct ASTNode* value;
            } Assignment;

            struct {
                struct ASTNode* left;
                int op;
                struct ASTNode* right; 
            } BinaryExpression;

            struct {
                struct ASTNode* test;
                struct ASTNode* consequent;
                struct ASTNode* alternate;
            } IfStatement;

            struct {
                struct ASTNode* id;
                struct ASTNode* start;
                struct ASTNode* end;
                struct ASTNode* body;

            } ForStatement;

            struct {
                struct ASTNode* body;
            } BlockStatement;
            
            struct {
                struct ASTNode* InsideBody;
                struct ASTNode* value;
            } Body;

            struct {
                struct ASTNode* value;
                char* strValue;
            } PrintStatement;
            
        };
    } ASTNode;


    // ASTfunction
    ASTNode* makeLiteralNode(int value);
    ASTNode* makeIDNode(char* id);
    ASTNode* makeBinExprNode(ASTNode* left, int op, ASTNode* right);
    ASTNode* makeVarDeclNode(char* kind, ASTNode* id, ASTNode* init);
    ASTNode* makeAssignNode(ASTNode* id, ASTNode* value);
    ASTNode* makeIfNode(ASTNode* test, ASTNode* consequent, ASTNode* alternate);
    ASTNode* makeBlockNode(ASTNode* body);
    ASTNode* makePrintNode(ASTNode* value, char* strValue);
    ASTNode* makeBodyNode (ASTNode* insideBody, ASTNode* value);
    ASTNode* makeForNode(ASTNode* id, ASTNode* start, ASTNode* end, ASTNode* body);