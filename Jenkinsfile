pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_ESTUDIANTE = 'https://github.com/Lou2714/TrianguloEjercicio.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{
        stage('Checking SCM'){
            steps{
                checkout scm
            }
        }
        stage('Getting test repository'){
            steps{
                dir('testing'){
                    git(
                        url: "${REPO_PRUEBAS}",
                        credentialsId: 'ProbandoJenkins',
                        branch: 'main'
                    )
                }
            }
        }
        stage('Move test directory'){
            steps{
                sh 'mv testing/* .'
            }
        }
        stage('Execute test'){
            steps{
                sh ("""
                    mkdir -p build
                    cmake -S . -B build
                    cmake --build build
                    ctest --test-dir build -O test-result.log --output-junit results.xml || true
                """)
            }
        }
        stage('Debug') {
            steps {
                sh 'pwd && ls -la'
            }
        }
    }
    post { 
        always { 
            cleanWs()
            echo 'I will always say Hello again!'
        }
    }
}