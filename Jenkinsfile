def score = 0
pipeline {
    agent {
        label 'linux' //A ver que tal x2
    }
    //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
    environment {
        ACCESS_KEY = credentials('repo-token')
        EMAIL = '00090220@uca.edu.sv'
    }
    stages {
        stage('Checkout') {
            steps {
                checkout scm // Clona el repositorio
            }
        }
        stage('Create Build Directory') {
            steps {
                sh 'mkdir -p build'
            }
        }

        stage('Configure Project with CMake') {
            steps {
                sh 'cmake -S . -B build'
            }
        }

        stage('Build Project') {
            steps {
                sh 'cmake --build build'
            }
        }

        stage('Run Tests') {
            steps {
            /*
            script {
                def result = sh(script: 'ctest --test-dir build -O waiting.log --output-junit results.xml', returnStatus: true)
                if (result != 0) {
                    echo "Advertencia: Algunas pruebas fallaron, pero continuamos."
                    }
                }
            }
            */
            sh 'ctest --test-dir build -O test-result.log --output-junit results.xml || true'
            }
        }

        stage('Evaluate Results') {
            steps {
                script {
                    def total_tests = sh(script: "grep -oP '(?<=tests=\")\\d+' build/results.xml", returnStdout: true).trim()
                    def failed_tests = sh(script: "grep -oP '(?<=failures=\")\\d+' build/results.xml", returnStdout: true).trim()

                    total_tests = total_tests.isNumber() ? total_tests.toInteger() : 0
                    failed_tests = failed_tests.isNumber() ? failed_tests.toInteger() : 0
                    def passed_tests = total_tests - failed_tests
                    score = total_tests > 0 ? (passed_tests * 10) / total_tests : 0

                    echo "Total de pruebas: ${total_tests}"
                    echo "Pruebas aprobadas: ${passed_tests}"
                    echo "Pruebas fallidas: ${failed_tests}"
                    echo "Calificación: ${score}/10"

                }
            }
        }
        stage('Create Grade Branch'){
            steps{
                script{
                    def ramas = sh(script: "git branch -r", returnStdout: true).trim()
                    def date = sh(script: 'TZ="America/El_Salvador" date +"%d/%m/%Y %H:%M"', returnStdout: true).trim()
                    def repoURL = sh(script: "git config --get remote.origin.url", returnStdout: true).trim()
                    def owner = sh(script: "git show -s --pretty=%an", returnStdout: true).trim()
        
        // Convertir URL HTTPS a formato autenticado
        def authRepoURL = repoURL.replace('https://', "https://${owner}:'$ACCESS_KEY'@")
        
        sh("""
            git checkout calificacion || git checkout -b calificacion
            echo "La calificación del día ${date} es: ${score}" >> calificaciones.md
            git config --local user.name "Lou2714"
            git config --local user.email "${EMAIL}"
            git pull ${authRepoURL} calificacion
            git add calificaciones.md
            git commit -m ":white_check_mark: Calificación"
            git push ${authRepoURL} calificacion
        """)
                    
                }
            }
        }
        // Este funciona
        stage('Update Pull Request'){
            steps{
                script{
                    def owner = sh(script: "git show -s --pretty=%an", returnStdout: true).trim()
                    def repoURL = sh(script: "git config --get remote.origin.url", returnStdout: true).trim()
                    def reponame = repoURL.split('/').last().replace('.git', '')
                    def updatePR = """
                        {
                            "title":"Calificación",
                            "body":"Tu nota es ${score} 😸 :) :P :3",
                            "state":"open",
                            "base":"main"
                        }
                    """
                    sh ("""
                        curl -L \
                        -X PATCH \
                        -H "Accept: application/json" \
                        -H 'Authorization: Bearer ${ACCESS_KEY}' \
                        -H "X-GitHub-Api-Version: 2022-11-28" \
                        "https://api.github.com/repos/${owner}/${reponame}/pulls/1" \
                        -d '${updatePR}'
                    """) 
                }
            }
        } 
    }
    post {
        always {
            echo 'Pipeline completado.'
        }
    }
}